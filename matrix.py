import numpy, sys, time

if (len(sys.argv) != 2):
    print "usage: python %s N" % sys.argv[0]
    quit()

file=open('p_re.dat','a')

N = int(sys.argv[1])

n= 2

for n in xrange(N+1):

    a = numpy.zeros((n, n)) # Matrix A
    b = numpy.zeros((n, n)) # Matrix B
    c = numpy.zeros((n, n)) # Matrix C

    # Initialize the matrices to some values.
    for i in xrange(n):
        for j in xrange(n):
            a[i, j] = i * n + j
            b[i, j] = j * n + i
            c[i, j] = 0

    begin = time.time()
    
    for i in xrange(n):
        for j in xrange(n):
            for k in xrange(n):
                c[i,j]+=a[i,k]*b[k,j];

    ######################################
    # Write code to calculate C = A * B. #
    ######################################

    end = time.time()
    print "time: %.6f sec" % (end - begin)
    file.write(str(n)+' '+str(end-begin)+'\n')

    # Print C for debugging. Comment out the print before measuring the execution time.
   # total = 0
  #  for i in xrange(n):
   #     for j in xrange(n):
            #       print c[i, j]
    #        total += c[i, j]
            # Print out the sum of all values in C.
            # This should be 450 for N=3, 3680 for N=4, and 18250 for N=5.
     #       print "sum: %.6f" % total
   # sum=0
file.close()
