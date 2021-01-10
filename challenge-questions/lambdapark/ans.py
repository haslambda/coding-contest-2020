children = int(input())
adults = int(input())

total = 10000 * adults + 8000 * children
discount = 0
if (children + adults >= 10):
  discount = 10
  if (children >= 5):
    discount = 20
total *= (100 - discount) / 100
print(int(total))
