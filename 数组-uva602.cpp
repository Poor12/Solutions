#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std ;

const int maxn = 20 ;

const char wrr[][maxn] = { "Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" } ;
const char mrr[][maxn] = { "" , "January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December" } ;

bool isLeap( int year , bool old = false )
{
    if ( old )
    {
        return year % 4 == 0 ? true : false ;
    }
    return ( year % 100 == 0 ? ( year % 400 == 0 ? true : false ) : ( year % 4 == 0 ? true : false ) ) ;
}

int days_of_month( int month , int year , bool leap )
{
    if ( month == 2 )
        return leap ?29 : 28 ;
    int d ;
    switch ( month )
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            d = 31 ;
        break ;
        default :
            d = 30 ;
    }
    return d ;
}

int days_of_year( int year , bool old )
{
    return isLeap( year , old ) ? 366 : 365 ;
}

int getNum ( char s[] , const char ss[][maxn] , int tot )
{
    int i = 0 ;
    while ( i < tot && strcmp ( s , ss[i] ) )
    {
        ++ i ;
    }
    return i < tot ? i : -1 ;
}

bool valid ( int month , int day , int year , bool old )
{
    if ( year < 1 )
        return false ;
    if ( month < 0 || month > 12 )
        return false ;
    if ( day < 1 || day > days_of_month( month , year , isLeap(year , old ) ) )
        return false ;
    return true ;
}

bool isold ( int month , int day , int year )
{
    return year < 1752 || ( year == 1752 && month < 9 ) || ( year == 1752 && month == 9 && day <= 2 ) ;
}

int main ()
{
    int month , year , day ;
    while ( scanf ( "%d %d %d" , &month , &day , &year ) != EOF && month + day + year )
    {
        bool old = isold( month , day , year ) ;
        if ( !valid( month , day , year , old ) )
        {
            cout << month << "/" << day << "/" << year << " is an invalid date." << endl ;
        }
        else
        {
            int sum = 0 ;
            for ( int y = 1 ; y < year ; y ++ )
            {
                sum += days_of_year(y,old) ;
            }
            for ( int m = 1 ; m < month ; m ++ )
            {
                sum += days_of_month( m , year , isLeap(year , old ) ) ;
            }
            sum += day ;
            int week = sum % 7 ;
            if ( old )
            {
                week = ( week + 5 ) % 7 ;
            }
            cout << mrr[month] << " " << day << "," << year <<" is a " << wrr[week] << endl ;
        }
    }
    return 0 ;
}