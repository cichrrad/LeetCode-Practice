#!/bin/bash

# Check if the number of arguments is exactly 2
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <difficulty> <problem_id>"
    echo "<difficulty> := easy | medium | hard"
    echo "<problem_id> := <positive integer>"
    exit 1
fi

# Assign arguments to variables
difficulty=$1
problem_id=$2

# Check if difficulty is valid
if [[ "$difficulty" != "easy" && "$difficulty" != "medium" && "$difficulty" != "hard" ]]; then
    echo "Error: Difficulty must be 'easy', 'normal', or 'hard'."
    exit 1
fi

# Check if problem_id is a positive integer
if ! [[ "$problem_id" =~ ^[0-9]+$ ]] || [ "$problem_id" -le 0 ]; then
    echo "Error: Problem ID must be a positive integer."
    exit 1
fi

# Create and change into the difficulty directory
if [ ! -d "$difficulty" ]; then
    mkdir "$difficulty"
fi
cd "$difficulty"

# Create the problem_id directory if it doesn't exist
if [ ! -d "$problem_id" ]; then
    mkdir "$problem_id"
fi
cd "$problem_id"

# Create an empty solution.cpp file if it doesn't already exist
if [ ! -f "solution.cpp" ]; then
    touch "solution.cpp"
fi

echo "Created directory structure for $difficulty/$problem_id and solution.cpp file."
