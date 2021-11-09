from sys import argv
from os import system

if __name__ == "__main__":
    '''
    echo $fileName
    
    ./build/$fileName.
    '''

    fileName = argv[1].split("/")[-1]

    system("g++ {} -o \"build/{}.o\" --std=c++11 `pkg-config --cflags --libs opencv`".format(argv[1], fileName))

    system("./build/{}.o".format(fileName))