package main

func main() {
	// 문자열 상수는 리터럴이다.
	// 컴파일 타임에 실제 리터럴로 변환하기 때문에
	// CPU 자원을 쓰지 않는다.
	// 상수의 메모리 주소값에 접근할 수 없는 이유는 컴파일 타임에 리터럴이 전환되어서 실행 파일에
	// 값의 형태로 저장되기 때문이다.
	// 동적 할당 메모리 영역을 사용하지 않는다.
	const arrEx string = "Hello World"
	print(arrEx)
}
