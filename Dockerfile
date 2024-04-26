# Get gcc:12.2.0 image
FROM gcc:12.2.0

# Set working directory to /app
WORKDIR /app

# Update and install gdb and valgrind
RUN apt-get update && apt-get install -y \	
	gdb \
	valgrind
