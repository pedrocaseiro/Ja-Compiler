class main {
	public static void main() {
		if (test); // Should print block

		if (test) { // Should not print block
			a=b;
		}

		if (test) // Should not print block
			a=b;

		if (test) {
			a=b;
			c=d;
		}

		if (test) {}

		if (test); else {}
	}
}