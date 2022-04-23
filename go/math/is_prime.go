func isPrime(a int) bool {
	for i := 2; a >= i*i; i++ {
		if a%i == 0 {
			return false
		}
	}
	return true
}