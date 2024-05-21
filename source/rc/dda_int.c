/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda_int.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/21 12:05:10 by tim           #+#    #+#                 */
/*   Updated: 2024/05/21 12:06:39 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_map.h"

//  IntegerLineDDA(int xa, int ya, int xb, int yb)    // to draw a line from (xa, ya) to (xb, yb)
//       {
//            int dx = xb - xa, dy = yb - ya;
//            int steps = dx, k;
//            int x = xa, y = ya;
//            int c = 0;
//            Draw(xa, ya);   // draw the pixel (xa, ya)
//            for (k=0; k<steps; k++) {
//                   x = x + 1;
//                   c = c + dy;  // update the fractional part
//                   if (c > dx)   { // (that is, the fractional part is greater than 1 now
//                         y = y+1;   // carry the overflowed integer over
//                         c = c - dx  // update the fractional part
//                         Draw(x, y);   // draw the new pixel
//             }
//        }

t_isct		integer_dda(int xa, int ya, int xb, int yb)
{
	int dx = xb - xa, dy = yb - ya;
	
}