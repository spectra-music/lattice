#include <cspec.h>
#include <cspec_output_header.h>
#include <cspec_output_verbose.h>
#include <cspec_output_unit.h>
#include <string.h>
#include "lattice.h"



/* DESCRIBE(get_full_path_nonexistant, "Resolve a full path from a nonexistant file") */
/* END_DESCRIBE */


DESCRIBE(prepend_string, "Prepends a string") {

  IT("prepends the string") {
    char string[11] = "hello";
    prepend_string(string, "pre");
    SHOULD_EQUAL(0, strcmp(string, "prehello"));
  } END_IT;

} END_DESCRIBE;

int main() {
	/* Run the description with verbose output => as much information as possible is output:
	 	- descriptions
		- tests
		- tests results
	*/
	CSpec_Run( DESCRIPTION( prepend_string ), CSpec_NewOutputVerbose() );
	return 0;
}
