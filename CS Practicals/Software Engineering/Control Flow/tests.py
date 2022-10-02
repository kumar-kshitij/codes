from program import sort
import unittest
import sys
import re


class TestProgram(unittest.TestCase):
    def test_if_sort_works_correctly(self):
        f = open('input.txt', 'w')
        f.write('5\n1\n4\n2\n3\n5')
        f.close()

        stdin = sys.stdin
        inputFile = open('input.txt', 'r')
        sys.stdin = inputFile

        stdout = sys.stdout
        outputFile = open('output.txt', 'w')
        sys.stdout = outputFile

        sort()

        sys.stdin = stdin
        inputFile.close()

        sys.stdout = stdout
        outputFile.close()

        f = open('output.txt', 'r')
        self.assertEqual(re.sub(r'\s+', '', f.read()), '[1,2,3,4,5]')
        f.close()


if __name__ == '__main__':
    unittest.main()
