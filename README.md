# Forest Fire Simulation

This repository contains a C++ program to simulate the spread of a forest fire over a period of seven days. The simulation is based on specified probabilities for trees catching fire and burning out.

## Introduction
The program is designed to model the spread of a forest fire over a linear arrangement of ten trees, one of which is initially on fire. The simulation runs for seven days, with updates occurring in the afternoon and evening of each day.

## Features
- **Simulation Rules**: The simulation follows specific rules for fire spread and burnout, as described in the problem statement.
- **Randomness**: The simulation incorporates randomness using C++'s random number generator to determine whether a tree catches fire or burns out.
- **Probabilistic Events**: Trees catching fire and burning out are modeled with probabilities specified in the problem statement.
- **Avoiding Bugs**: The code is structured to avoid a potential bug in the afternoon update, ensuring accurate simulation results.

## Usage
To run the simulation, simply compile the provided `fire.cpp` file and execute the generated binary. The program will simulate the forest fire and output the final state of the forest.

## Results
The program estimates the probability of at least one tree remaining on fire after seven days of simulation. This estimation is based on running the simulation multiple times and counting the occurrences of a tree remaining on fire.

## Files
- `fire.cpp`: The main C++ source code file containing the simulation implementation.
- `README.md`: This file providing an overview of the project.

## Requirements
- C++ compiler with support for C++11 or later.
- Standard Library headers (`<iostream>`, `<random>`).
