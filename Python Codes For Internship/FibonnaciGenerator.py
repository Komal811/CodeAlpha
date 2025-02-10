#count is the number of fibonnaci number that will print out

def fibonnaci(count) :
	first=0
	second=1
	print (first)
	print (second)

	for i in range(0,count-2) :
		third=first+second
		print (third)
		first=second
		second=third

title="Welcome to Fibonacci Generator"
title.center (83)

count=int (input ("Enter the Number of Fibonacci Numbers to show: ") )

fibonnaci(count)

print ('\n\nThank You')