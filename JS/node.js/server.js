// Express 서버 만들기 
var express = require("express");
var app = express();
var router = require('./router/main')(app); // Router에 APP 전달 

// 서버가 읽을 수 있도록 HTML 위치를 정의
// 서버가 HTML 렌더링시 EJS 엔진을 사욛하도록 함. 
app.set('views', __dirname + '/views');
app.set('view engine', 'ejs');
app.engine('html', require('ejs').renderFile);

// 정적 파일 다루기 
app.use(express.static('public')); 

var server = app.listen(3000, function(){
    console.log("Express server has started on port 3000")
});

