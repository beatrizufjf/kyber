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
include CMakeFiles/sha2_ref.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sha2_ref.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sha2_ref.dir/flags.make

CMakeFiles/sha2_ref.dir/sha256.o: CMakeFiles/sha2_ref.dir/flags.make
CMakeFiles/sha2_ref.dir/sha256.o: ../sha256.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sha2_ref.dir/sha256.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sha2_ref.dir/sha256.o -c /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha256.c

CMakeFiles/sha2_ref.dir/sha256.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sha2_ref.dir/sha256.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha256.c > CMakeFiles/sha2_ref.dir/sha256.i

CMakeFiles/sha2_ref.dir/sha256.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sha2_ref.dir/sha256.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha256.c -o CMakeFiles/sha2_ref.dir/sha256.s

CMakeFiles/sha2_ref.dir/sha512.o: CMakeFiles/sha2_ref.dir/flags.make
CMakeFiles/sha2_ref.dir/sha512.o: ../sha512.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sha2_ref.dir/sha512.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sha2_ref.dir/sha512.o -c /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha512.c

CMakeFiles/sha2_ref.dir/sha512.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sha2_ref.dir/sha512.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha512.c > CMakeFiles/sha2_ref.dir/sha512.i

CMakeFiles/sha2_ref.dir/sha512.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sha2_ref.dir/sha512.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/sha512.c -o CMakeFiles/sha2_ref.dir/sha512.s

# Object files for target sha2_ref
sha2_ref_OBJECTS = \
"CMakeFiles/sha2_ref.dir/sha256.o" \
"CMakeFiles/sha2_ref.dir/sha512.o"

# External object files for target sha2_ref
sha2_ref_EXTERNAL_OBJECTS =

libsha2_ref.a: CMakeFiles/sha2_ref.dir/sha256.o
libsha2_ref.a: CMakeFiles/sha2_ref.dir/sha512.o
libsha2_ref.a: CMakeFiles/sha2_ref.dir/build.make
libsha2_ref.a: CMakeFiles/sha2_ref.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libsha2_ref.a"
	$(CMAKE_COMMAND) -P CMakeFiles/sha2_ref.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sha2_ref.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sha2_ref.dir/build: libsha2_ref.a

.PHONY : CMakeFiles/sha2_ref.dir/build

CMakeFiles/sha2_ref.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sha2_ref.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sha2_ref.dir/clean

CMakeFiles/sha2_ref.dir/depend:
	cd /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512 /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512 /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test /app/NIST-PQ-Submission-Kyber-20201001/Optimized_Implementation/crypto_kem/kyber512/test/CMakeFiles/sha2_ref.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sha2_ref.dir/depend

