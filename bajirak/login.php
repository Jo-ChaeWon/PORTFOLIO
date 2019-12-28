<!DOCTYPE HTML>
<html>  
<body>
<style>
table, td, th {
    corlor: white;
}
   
td {
    height: 30px;
}
	  
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
<title>로그인</title>
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


<?php //로그인을 하지 않았을 때는 로그인 창을 보여준다.

session_start(); // 세션

if($_SESSION['id']==null) { // 로그인 하지 않았다면

?>

<div> 
    <h1 class="h2" align="center"> 로그인</h1><hr> <!--로그인 글씨 가운데로-->
</div>


<div align="center">
               
    <form method='get' action='login2.php' style="margin: 30 290px 0 300px; border: solid 1px; border-radius:4px;">
    <table>
        <tr>
        <td>아이디: </td>
            <td><input type="text" name="id"> </td>
        </tr>
                  
        <tr>
        <td>비밀번호: </td>
            <td><input type="password" name="pw"></td>
        </tr>
		
		<td  align="center">
            <input type="submit" value="로그인">
        </td>
		<script>
			function replace10() {
			location.replace("http://jupiter.mokpo.ac.kr/~bajirak/join.php")
			}
		</script>
		<td  align="center">
			<input type="button" value="회원가입" onClick="replace10()">
		</td>
		
	</form>	
</div>
<?php

}else{ // 로그인 했다면 로그아웃 버튼을 출력한다.
   echo "<center><br><br><br>";
   echo $_SESSION['name']."[".$_SESSION['id']."]님이 로그인 하였습니다. <br>";
   echo "&nbsp;<a href='member.php'><input type='button' value='회원정보'></a>";
   echo "&nbsp;<a href='logout.php'><input type='button' value='로그아웃'></a>";
   echo "</center>";
}

?>

</body>
</html>