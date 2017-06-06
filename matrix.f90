!モジュール 

module mul
  implicit none
  integer, parameter :: n = 3  ! 正方行列の次元
contains

  subroutine mul_matrix(a,b,c)
    real(8), intent(in) :: a(n,n), b(n,n)
    real(8), intent(out) :: c(n,n) 
    integer::i,j,k
    do i = 1, n
       do j = 1, n
          do k = 1, n
             c(i,j) = c(i,j) + a(i,k)*b(k,j)
          end do
      !    write(*,'(5f22.15)') (c(i,j))
       end do
    end do

  end subroutine mul_matrix
end module mul




program matrix
  use mul
  implicit none
  integer::i,j,sum,time,f_time,t_rate,t_max,diff
  real(8):: a(n,n), b(n,n), c(n,n)

  do i=1,n
     do j=1,n
        a(i,j)=(i-1)*n+(j-1)
        !Cと並び方違う(二次元配列でもメモリ内部では一次元)、初期化必要
        b(i,j)=(j-1)*n+(i-1)
        c(i,j)=0
        !       write(*,'(5f22.15)') (b(i,j))
     end do
  end do

  !  long begin = System.currentTimeMillis();
  call system_clock(time)

  call mul_matrix(a,b,c) !最初の14だけ0

  call system_clock(f_time, t_rate, t_max)
  !計測終わり

   if (f_time<time) then
    diff = (t_max - time) + f_time + 1
  else
    diff = f_time - time
  endif
  print "(A, F10.3)", "time:", diff/dble(t_rate)

  sum=0


  do i=1,n
     do j=1,n
        sum=sum+c(i,j)
     end do
  end do
  write(*,*) 'sum:',sum

end program matrix
