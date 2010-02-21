# Example SConstruct File for a CppUTest project
import os.path 
from os import getcwd

# Construct variables for the SUT and test binaries
# This is based on the base directory name that SConstruct lives in
component_name = os.path.basename(getcwd()) 
component_tests_name = component_name + "_tests"

# Construct the list of source files for the SUT
prod_src = Glob('src/*.cpp') + Glob('src/util/*.cpp')

# Construct the list of source files for the test program
test_src = Glob('tests/*.cpp') + Glob('tests/util/*.cpp')  

# Define the dependencies of the test program 

# Find CppUTest unit test framework root dir
# Bail out if this is not defined as an ENV var
try:
  cpputest_home_path = os.environ['CPP_U_TEST'] 
  cpputest_include_path = cpputest_home_path + "/include"
  cpputest_lib_path = cpputest_home_path + "/lib"
  cpputest_lib = 'libCppUTest.a'
except KeyError:
  print "Can't find CppUTest framework; set environment variable 'CPP_U_TEST'\n"
  Exit()

# Define the C++ Includes path
cpp_includes_path = Split(". include include/util") 
cpp_includes_path.append(cpputest_include_path)

# Define the library path that the test executable requires 
test_lib_path = Split('.')
test_lib_path.append(cpputest_lib_path)

# Create the scons build environment object, with 'CPPPATH' for compiler 'includes'
env = Environment( CPPPATH = cpp_includes_path )

# Build the production code (SUT) as a static library
prod_lib = env.Library( target = component_name, source = prod_src, ) 

# Build the executable tests as a normal binary
test_executable = env.Program( target = component_tests_name, source = test_src, LIBS=[prod_lib, cpputest_lib], LIBPATH=test_lib_path )

# Run the tests with the command 'scons check'
env.Alias("check", test_executable, "./$SOURCE")
