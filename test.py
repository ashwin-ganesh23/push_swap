from subprocess import call
import random
args = ""
int_list = random.sample(range(-1000000,1000000), 500)
print(int_list)
for i in int_list:
    args += ' '
    args += str(i)

call(["./push_swap", args])
