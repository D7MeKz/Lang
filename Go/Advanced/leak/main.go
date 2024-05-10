package main

func getPart(msg []byte) []byte {
	msgType := make([]byte, 5)
	copy(msgType, msg)
	return msgType
}
