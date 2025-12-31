# Top-level CMakeLists.txt
cmake_minimum_required(VERSION 4.1) # Adjust version as needed
project(JarvisBuildTools C)

# Add subdirectories for different components
add_subdirectory(JWasm)
add_subdirectory(JWlink/dwarf)
add_subdirectory(JWlink)