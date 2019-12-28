<!DOCTYPE>
 
<html>
<head>
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

		<li>선적 그래프</li>
		
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
 
        <div>
         <h1 class="h2" align="center"> 회원목록</h1><hr>
      </div>

<?php

   $servername = "localhost";
   $username = "bajirak";
   $password = "1234";
   $dbname = "bajirakdb";

   // 데베 연결
   $conn = new mysqli($servername, $username, $password, $dbname);

   // 연결 확인
   if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
   }
   
   $sql = "select * from member";
   
   $result = $conn->query($sql);
   
    echo '<table class="text-center" style="width:100%"><tr>' .
         '<th>아이디</th>
          <th>비밀번호</th>
		  <th>email</th>' .
	     '</tr>';
   
   while($row = $result->fetch_array()){
	   echo("
        <tr>
        <td align='center'>$row[id]</td>
        <td align='center'>$row[pw]</td>
        <td align='center'>$row[email]</td>
		<td  align='center'><a href=delete.php>삭제  </a><a href=update.php>  수정</a></td>
        </tr>
	");
	}
	echo '</table>';
   
   $conn->close();
   ?>
   
	
</html>
</html>