from itertools import permutations
from itertools import product
from itertools import combinations
from itertools import combinations_with_replacement

a = [1,2,3,4,5]
b = [1,2,3,4,1]
print('순열')
print(list(permutations(a, 2)))
print(list(permutations(b, 2)))
print('----------')

print('중복순열')
print(list(product(a, repeat=2)))
print(list(product(b, repeat=2)))
print('----------')

print('조합')
print(list(combinations(a, 2)))
print(list(combinations(b, 2)))
print('----------')

print('중복 조합')
print(list(combinations_with_replacement(a, 2)))
print(list(combinations_with_replacement(b, 2)))