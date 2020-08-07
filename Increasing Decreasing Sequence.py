n=int(input())
prev=0
flag=0
cnt=0
if n==1:
	print('false')
	exit(0)
for i in range(n):
	x=int(input())
	if i==0:
		prev=x
		continue
	if(x>prev):
		if(flag==0):
			cnt+=1
		flag=1
		
	else:
		if(flag==1):
			cnt+=1;
		flag=0
		
	prev=x
if(cnt>1):
	print('false')
else:
	print('true')


