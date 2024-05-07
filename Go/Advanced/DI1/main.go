package main

type Pet struct {
	name string
}

// Wrong
// 읽기 좋지 못하는 코드
type WideFormatter1 interface {
	ToCSV(pets []Pet) ([]byte, error)
	ToExcel(pets []Pet) ([]byte, error)
}

// 읽기 좋은 코드
type Formatter interface {
	Format(pets []Pet) ([]byte, error)
}

type CSVFormatter struct{}

func (C CSVFormatter) Format(pets []Pet) ([]byte, error) {
	//TODO implement me
	panic("implement me")
}
