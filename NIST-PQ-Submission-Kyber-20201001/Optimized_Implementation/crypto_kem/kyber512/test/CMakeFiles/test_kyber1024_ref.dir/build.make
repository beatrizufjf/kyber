# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test

# Include any dependencies generated for this target.
include CMakeFiles/test_kyber1024_ref.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_kyber1024_ref.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_kyber1024_ref.dir/flags.make

CMakeFiles/test_kyber1024_ref.dir/test_kyber.o: CMakeFiles/test_kyber1024_ref.dir/flags.make
CMakeFiles/test_kyber1024_ref.dir/test_kyber.o: ../test_kyber.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_kyber1024_ref.dir/test_kyber.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_kyber1024_ref.dir/test_kyber.o -c /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test_kyber.c

CMakeFiles/test_kyber1024_ref.dir/test_kyber.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_kyber1024_ref.dir/test_kyber.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test_kyber.c > CMakeFiles/test_kyber1024_ref.dir/test_kyber.i

CMakeFiles/test_kyber1024_ref.dir/test_kyber.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_kyber1024_ref.dir/test_kyber.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test_kyber.c -o CMakeFiles/test_kyber1024_ref.dir/test_kyber.s

CMakeFiles/test_kyber1024_ref.dir/randombytes.o: CMakeFiles/test_kyber1024_ref.dir/flags.make
CMakeFiles/test_kyber1024_ref.dir/randombytes.o: ../randombytes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_kyber1024_ref.dir/randombytes.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_kyber1024_ref.dir/randombytes.o -c /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/randombytes.c

CMakeFiles/test_kyber1024_ref.dir/randombytes.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_kyber1024_ref.dir/randombytes.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/randombytes.c > CMakeFiles/test_kyber1024_ref.dir/randombytes.i

CMakeFiles/test_kyber1024_ref.dir/randombytes.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_kyber1024_ref.dir/randombytes.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/randombytes.c -o CMakeFiles/test_kyber1024_ref.dir/randombytes.s

# Object files for target test_kyber1024_ref
test_kyber1024_ref_OBJECTS = \
"CMakeFiles/test_kyber1024_ref.dir/test_kyber.o" \
"CMakeFiles/test_kyber1024_ref.dir/randombytes.o"

# External object files for target test_kyber1024_ref
test_kyber1024_ref_EXTERNAL_OBJECTS =

test_kyber1024_ref: CMakeFiles/test_kyber1024_ref.dir/test_kyber.o
test_kyber1024_ref: CMakeFiles/test_kyber1024_ref.dir/randombytes.o
test_kyber1024_ref: CMakeFiles/test_kyber1024_ref.dir/build.make
test_kyber1024_ref: libkyber1024_ref.a
test_kyber1024_ref: CMakeFiles/test_kyber1024_ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_kyber1024_ref"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_kyber1024_ref.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_kyber1024_ref.dir/build: test_kyber1024_ref

.PHONY : CMakeFiles/test_kyber1024_ref.dir/build

CMakeFiles/test_kyber1024_ref.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_kyber1024_ref.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_kyber1024_ref.dir/clean

CMakeFiles/test_kyber1024_ref.dir/depend:
	cd /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512 /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512 /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles/test_kyber1024_ref.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_kyber1024_ref.dir/depend

