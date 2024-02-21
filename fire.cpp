#include <iostream>
#include <random>

using std::cout; using std::cin; using std::endl;

// Variables which are declared outside of any function are said to be GLOBAL.
// This means that they will be usable both in main(), as well as any other functions 
// that you choose to write.
//
// Global variables are frowned upon.  But the variables below don't contain
// important information that is likely to change, so making them global isn't particularly treacherous.
std::random_device ran_dev;
std::mt19937 generator( ran_dev() );
std::uniform_real_distribution<>  dist(0.0, 1.0);

const double PROB_CATCH_FIRE = 0.4;  // The const qualifier prevents these variables from being modified;
const double PROB_BURN_OUT = 0.2;    // any attempt to change them later will cause a compilation error.

/*  Generates whether the tree will catch fire
	@return 	    True or False depending on the probability of the tree catching on fire
*/
bool catchFire()
{
    return dist(generator) <= PROB_CATCH_FIRE;
}

/*  Generates whether the tree will burn out
	@return         True or False depending on the probability of the tree burning out
*/
bool burnOut()
{
    return dist(generator) <= PROB_BURN_OUT;
}

/*  Simulates a fire spreading within the forest
    @param forest   A character array consisting of trees 
    @param arrLen   The length of the char array
*/
void simulateFire(char forest[], int arrLen)
{
    int l = 0;
    int r = arrLen - 1;
    // two pointer approach
    while(l < r)
    {
        // case 1: left pointer detects fire
        if (forest[l] == 'F')
        {
            // check left 
            if(forest[l - 1] == 't' && catchFire())
            {
                // set left tree on fire
                forest[l - 1] = 'N';
            }

            // check right
            if(forest[l + 1] == 't' && catchFire())
            {
                // set right tree on fire
                forest[l + 1] = 'N';
                l += 2;
            }
        }
        l++;

        // case 2: right pointer detects fire
        if (forest[r] == 'F')
        {
            // check right
            if(forest[r + 1] == 't' && catchFire())
            {
                // set right tree on fire
                forest[r + 1] = 'N';
            }
            // check left 
            if(forest[r - 1] == 't' && catchFire())
            {
                // set left tree on fire
                forest[r - 1] = 'N';
                r -= 2;
            }
        }
        r--;
        
        // since the new fires are set to N
        // we will switch out N with F after every iteration
        for (int i = 0; i < arrLen; i++)
        {
            if (forest[i] == 'N')
            {
                forest[i] = 'F';
            }
        }
    }
}

/*  Simulates a burn out of trees on fire
    @param forest   A character array consisting of trees 
    @param arrLen   The length of the char array
*/
void simulateBurnOut(char forest[], int arrLength)
{
    // iterate through array
    for (int i = 0; i < arrLength; i++)
    {
        // site is on fire, 0.2 probability of burn out
        if (forest[i] == 'F' && burnOut())
        {
            forest[i] = 'x';
        }
    }
}

/*  Simulates seven days of events including 7 afternoons and evenings
    @param forest   A character array consisting of trees 
    @param arrLen   The length of the char array
    @return         True or False, whether the forest still consistent of 
                    one tree on fire at the end of the seven days
*/
bool simulateSevenDays(char forest[], int arrLength)
{
    bool found = false;
    // simulating 7 afternoons and evenings
    for (int i = 0; i < 7; i++)
    {
        simulateFire(forest, arrLength);
        simulateBurnOut(forest, arrLength);
    }
    // checking for the last day for one site on fire
    for(int j = 0; j < 12; j++)
    {
        if (forest[j] == 'F')
        {
            found = true;
        }
    }
    return found;
}

int main() {

    char forest[12] = {'x', 't', 't', 't', 't', 'F', 't', 't', 't', 't', 't', 'x'};
    int arrLength = 12;
    double simulations = 10000000;
    double oneOnFireCount = 0;

    // running simulation to find the probability
    for (int i = 0; i < simulations; i++)
    {
        char newForest[12];
        for (int j = 0; j < arrLength; j++)
        {
            newForest[j] = forest[j];
        }
        if (simulateSevenDays(newForest, arrLength) == true)
        {
            oneOnFireCount++;
        }
    }
    cout << oneOnFireCount / simulations;

    return 0;
}