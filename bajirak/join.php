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
		<h1 class="h2" align="center"> 회원가입</h1><hr>
    </div>
      
      
      <div align="center">
               
                <form method='get' action='join2.php' style="margin: 30 290px 0 300px; border: solid 1px; border-radius:4px;">
               <table>
                  <tr>
                     <td>아이디: </td>
                     <td><input type="text" name="id"> </td>	
                  </tr>
                  
                  <tr>
                     <td>비밀번호: </td>
                     <td><input type="password" name="pw"></td>
                  </tr>
                  
                  <tr>
                     <td>비밀번호 확인:</td>
                     <td><input type="password" name="pw2"></td>
                  </tr>
                  
                  <tr>
                     <td>e-mail: </td>
                     <td><input type="email" name="email"></td>
                  </tr>
                  
                  <td colspan="2" align="center">
                     <input type="submit" value="회원가입">
                  </td>
                </form>
        </div>      
</body>
</html>