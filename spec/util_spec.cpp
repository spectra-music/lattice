#include "lattice_util.h"
#include "cppspec.hpp"

using namespace std;

describe util_spec("util.c", _blk {
	context("get_full_path_nonexistant(char*, const char*)", _blk {
		it("'/' should resolve to '/'", _blk {
			char dest[2];
			get_full_path_nonexistant(dest,"/");
			expect(dest).to_equal(string("/"))();
		});

		it("\"/something\" should resolve to \"/something\"", _blk {
			char dest[50];
			get_full_path_nonexistant(dest, "/something");
			expect(dest).to_equal(string("/something"))();
		});

		it("\"/some/new/path\" should resolve to \"/some/new/path\"", _blk {
			char dest[50];
			get_full_path_nonexistant(dest,"/some/new/path");
			expect(dest).to_equal(string("/some/new/path"))();
		});

		it("\"/usr/include/lattice\" should resolve to \"/usr/include/lattice\"", _blk {
			char dest[50];
			get_full_path_nonexistant(dest,"/usr/include/lattice");
			expect(dest).to_equal(string("/usr/include/lattice"))();
		});

		it("\"file\" should resolve to \"./file\"", _blk {
			char dest[50];
			get_full_path_nonexistant(dest,"file");
			expect(dest).to_equal(string("./file"))();
		});

		it("\"a/new/file\" should resolve to \"./a/new/file\"", _blk {
			char dest[50];
			get_full_path_nonexistant(dest,"a/new/file");
			expect(dest).to_equal(string("./a/new/file"))();
		});
	});
});

int main(void) {
	util_spec.run();
}