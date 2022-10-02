from program import program
import unittest
import sys
import re

stdin = None
inputFile = None
stdout = None
outputFile = None


def writeInput(input):
    f = open('input.txt', 'w')
    f.write(input)
    f.close()


def readOutput():
    f = open('output.txt', 'r')
    output = re.sub(r'\s+', '', f.read())
    f.close()
    return output


def setFileStream():
    global stdin, inputFile
    stdin = sys.stdin
    inputFile = open('input.txt', 'r')
    sys.stdin = inputFile

    global stdout, outputFile
    stdout = sys.stdout
    outputFile = open('output.txt', 'w')
    sys.stdout = outputFile


def unsetFileStream():
    if stdin is not None:
        sys.stdin = stdin
    if inputFile is not None:
        inputFile.close()

    if stdout is not None:
        sys.stdout = stdout
    if outputFile is not None:
        outputFile.close()


class TestProgram(unittest.TestCase):
    def test_path_1(self):
        writeInput('-1.5\n1')
        setFileStream()
        program()
        unsetFileStream()
        self.assertEqual(readOutput(), '-1.5')

    def test_path_2(self):
        writeInput('1.5\n1')
        setFileStream()
        program()
        unsetFileStream()
        self.assertEqual(readOutput(), '1.0')

    def test_path_3(self):
        writeInput('4.5\n1')
        setFileStream()
        program()
        unsetFileStream()
        self.assertEqual(readOutput(), '4.5')


if __name__ == '__main__':
    unittest.main()
