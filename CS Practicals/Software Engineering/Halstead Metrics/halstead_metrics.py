from bubbleSort import bubbleSort
import json
import re
import math

arr = [11, 8, 108, 205, 119]
bubbleSort(arr)
print('Bubble Sort result:', arr)

with open('bubbleSort.py', 'r') as f:
    program = f.read()
program = re.sub(r'\s+', '', program)

with open('operators.json') as f:
    operators = json.load(f)

n1 = len(operators)
N1 = 0
for op in operators:
    N1 += len(re.findall(re.escape(op[0]
              if op in ['()', '{}', '[]'] else op), program))

delimiters = []
for op in operators:
    if op in ['()', '{}', '[]']:
        delimiters.extend(list(map(lambda x: re.escape(x), list(op))))
    else:
        delimiters.append(re.escape(op))

operands = list(filter(lambda x: x != '',
                re.split('|'.join(delimiters), program)))
n2 = len(set(operands))
N2 = len(operands)

print("\nHalstead's Metrics:")

print('n1 = {}, n2 = {}, N1 = {}, N2 = {}'.format(n1, n2, N1, N2))
print('Program Vocabulary:', n1+n2)
print('Program Length:', N1+N2)

volume = (N1+N2)*math.log(n1+n2, 2)
print('Program Volume:', volume)

difficulty = (n1/2)*(N2/n2)
print('Program Level:', 1/difficulty)
print('Program Difficulty:', difficulty)
