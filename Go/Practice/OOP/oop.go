package main

type Report interface {
	Report()
}

type FinanceReport struct {
	report string
}

func (r *FinanceReport) Report() string {
	return r.report
}

// Send Report
// Activity
type ReportSender interface {
	Send(r *Report)
}

type FaxSender struct {
}

func (f *FaxSender) Send(r *Report) {

}

func main() {

}
