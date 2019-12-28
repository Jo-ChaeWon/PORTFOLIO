<!DOCTYPE HTML>
<html>  
<body>
<style>
ul{
font-size:200%;
	list-style:none;
	text-align:center;
	border-top:1px solid red; border-bottom:1px solid red; padding:10px 0;
}
ul li{
	display:inline;
	text-transform:uppercase;
	padding:0 50px; letter-spacing:10px;
}
ul li a {text-decoration:none; color:black;}
ul li a:hover{text-decoration:underline;}
</style>
<title>홈</title>
</head>
<body>
	<ul>
		<script>
   		 function replace1() {
      		 location.replace("http://jupiter.mokpo.ac.kr/~bajirak/home.php")
   		 }
 		</script>
 		<a href="#" onClick="replace1()"><li>홈</li></a>
	
		<script>
   		 function replace2() {
      		 location.replace("http://jupiter.mokpo.ac.kr/~bajirak/list2.php")
   		 }
 		</script>
 		<a href="#" onClick="replace2()"><li>선적 리스트</li></a>
		
		<script>
   		 function replace3() {
      		 location.replace("http://jupiter.mokpo.ac.kr/~bajirak/graph.php")
   		 }
 		</script>
 		<a href="#" onClick="replace3()"><li>선적 그래프</li></a>
		
		<script>
   		 function replace4() {
      		 location.replace("http://jupiter.mokpo.ac.kr/~bajirak/login.php")
   		 }
 		</script>
 		<a href="#" onClick="replace4()"><li>로그인</li></a>
		
		<script>
   		 function replace5() {
      		 location.replace("http://jupiter.mokpo.ac.kr/~bajirak/in.php")
   		 }
 		</script>
 		<a href="#" onClick="replace5()"><li>선적 정보관리</li></a>
	</ul>

<p>
<img src="ship.jpg" alt="배" style="float:center;" width=80% align="center">
</p>

</body>
</html>