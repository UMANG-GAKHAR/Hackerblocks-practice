num = input()
num=int(num)

# prime numbers are greater than 1
if num > 1:
    if num < 1000000001:
        
   # check for factors
       for i in range(2,num):
           if (num % i) == 0:
               print("Not Prime")
               break
       else:
           print("Prime")
    else:
        print("Please enter numbers between 1 and 1000000001 ")
       
# if input number is less than
# or equal to 1, it is not prime
else:
   print("Not Prime")
