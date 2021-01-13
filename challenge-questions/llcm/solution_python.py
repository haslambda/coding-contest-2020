'''nums = list(map(int, input().split()))'''

def gcf(a,b):
    if b % a == 0:
        return a
    else:
        b %= a
        gcf(b,a)
'''
def lcm(args):
    if (len(args) == 2):
        return args[0]*args[1]/gcf(args[0],args[1])
    else:
        return lcm(lcm(args[0],args[1]),lcm(args[2],args[3]))

print(lcm(2,4,5,7))
    '''
print(gcf(24,30))