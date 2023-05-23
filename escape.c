// example.c - Simple test print code


#include <stdint.h>
#include <tgmath.h>

#define ESCAPE_IMPLEMENTATION
#include "escape.h"

#define TEST_STRING "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"

void hsv_rgb( float h, float s, float v, uint8_t *r, uint8_t *g, uint8_t *b )
{
	//float v0 = v - v * s;
	float h0 = h * 6.0;

	float k = fmod( 5.0 + h0, 6.0 );
	*r = 255 * ( v - v * s * fmax( 0.0, fmin( k, fmin( 4.0 - k, 1.0 ) ) ) );

	k = fmod( 3.0 + h0, 6.0 );
	*g = 255 * ( v - v * s * fmax( 0.0, fmin( k, fmin( 4.0 - k, 1.0 ) ) ) );

	k = fmod( 1.0 + h0, 6.0 );
	*b = 255 * ( v - v * s * fmax( 0.0, fmin( k, fmin( 4.0 - k, 1.0 ) ) ) );
}

int main( void )
{
	fputs( ANSI_CLEAR_SCREEN, stdout );

	fputs( ANSI_CURSOR_POSITION( 1, 1 ), stdout );
	fputs( ANSI_CURSOR_POSITION( 3, 2 ) "X", stdout );	fflush( stdout );
	fputs( ANSI_CURSOR_POSITION( 10, 2 ) "X", stdout );  fflush( stdout );
	fputs( ANSI_CURSOR_POSITION( 10, 4 ) "X", stdout ); fflush( stdout );
	fputs( ANSI_CURSOR_POSITION( 3, 4 ) "X", stdout ); fflush( stdout );

	fputs( "\n\n", stdout );

	fputs( "\n" ANSI_SGR_RESET TEST_STRING "\n\n", stdout );
	fputs( ANSI_SGR_BOLD TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_OVERLINE TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_UNDERLINE TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_STRIKETHROUGH TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_FG_RGB( 0, 128, 128 ) TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_BG_RGB( 128, 0, 128 ) TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_BLINK TEST_STRING ANSI_SGR_RESET "\n\n", stdout );
	fputs( ANSI_SGR_REVERSE TEST_STRING ANSI_SGR_RESET "\n\n", stdout );

	fputs( "\n\n", stdout );

	uint8_t r,g,b;

	for( float i = 0; i < 1; i += 0.01 )
	{
		hsv_rgb( i, 1.0, 1.0, &r, &g, &b );

		ansi_sgr_fg_rgb( r, g, b );
		fputs( "█", stdout );
	}

	fputs( "\n", stdout );
}
