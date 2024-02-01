program numerical_integration
    implicit none
    real(8) :: a, b, integral
    integer :: n
    real(8) :: start, finish, elapsed

    ! Define the interval and the number of subdivisions
    a = 0.0d0
    b = acos(-1.0d0)  ! Pi, using double precision
    n = 100000000

    ! Timing the integration
    call cpu_time(start)
    call trapezoidal_rule(f, a, b, n, integral)
    call cpu_time(finish)

    elapsed = finish - start
    print *, "Integral: ", integral
    print *, "Time taken: ", elapsed, " seconds"

contains

    ! The function to be integrated
    function f(x) result(y)
        real(8), intent(in) :: x
        real(8) :: y

        y = sin(x)
    end function f

    ! Subroutine for the trapezoidal rule
    subroutine trapezoidal_rule(func, a, b, n, integral)
        interface
            function func(x)
                real(8), intent(in) :: x
                real(8) :: func
            end function func
        end interface
        real(8), intent(in) :: a, b
        integer, intent(in) :: n
        real(8), intent(out) :: integral
        real(8) :: h, x
        integer :: i

        h = (b - a) / n
        integral = 0.5d0 * (func(a) + func(b))
        do i = 1, n - 1
            x = a + i * h
            integral = integral + func(x)
        end do
        integral = integral * h
    end subroutine trapezoidal_rule

end program numerical_integration
