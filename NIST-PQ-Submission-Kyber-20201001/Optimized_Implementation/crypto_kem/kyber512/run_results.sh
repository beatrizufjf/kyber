#!/bin/bash

# Define the number of times to run the ./test_speed command
N=100

# Create the "results" folder if it doesn't exist
if [ ! -d "results" ]; then
    echo "Creating 'results' folder"
    mkdir results
fi

# Remove all files from the "results" folder
echo "Removing all files from the 'results' folder"
rm -f results/*

# Define possible values for SEC_K and IMPLEMENTATION
SEC_K_VALUES=(2 3 4)
IMPLEMENTATION_VALUES=("AES" "FORRO" "SHAKE" "XOTE")

# Loop through all combinations of SEC_K and IMPLEMENTATION
for SEC_K in "${SEC_K_VALUES[@]}"; do
    for IMPLEMENTATION in "${IMPLEMENTATION_VALUES[@]}"; do
        echo "Removing previous test_speed file"
        rm test_speed

        echo "Running make test_speed with SEC_K=$SEC_K and IMPLEMENTATION=$IMPLEMENTATION"
        make test_speed SEC_K=$SEC_K IMPLEMENTATION=$IMPLEMENTATION

        # Run the ./test_speed command N times
        for ((i=1; i<=N; i++)); do
            echo "Running ./test_speed (iteration $i/$N)"
            nice -n -20 ./test_speed
        done

        echo "------------------"
    done
done
