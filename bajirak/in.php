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
<title>선적 정보 관리</title>
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

	if($_SESSION['id']==null) {// 로그인 하지 않았다면
		?>
		<script>
            alert("로그인을 해주세요.");
            location.replace("./login.php");
        </script>		


<?php

}else{ // 로그인 했다면 선적배정정보 입력을 보여준다.
   


?>

<div>
	<h1 class="h2" align="center">  선석배정정보 입력 </h1><hr>
</div>

<div align="center">
               
    <form method='get' action='in2.php' style="margin: 30 290px 0 300px; border: solid 1px; border-radius:4px;">
    <table>
        <tr>
        <td>모선명 : </td>
            <td><input type="text" name="name"><br> </td>
        </tr>
		<tr>
        <td>모선항차 : </td>
            <td><input type="text" name="mno"><br> </td>
        </tr>
		<tr>
        <td>선사항차 : </td>
            <td><input type="text" name="sno"><br> </td>
        </tr>
		<tr>
        <td>선석 : </td>
            <td><input type="text" name="berth"><br> </td>
        </tr>
		<tr>
        <td>Bitt. A/B/F : </td>
            <td><input type="text" name="bitt"><br> </td>
        </tr>
		<tr>
        <td>접안현 : </td>
            <td><input type="text" name="ps"><br> </td>
        </tr>
		<tr>
        <td>마감시간 : </td>
            <td><input type="text" name="deadine"><br> </td>
        </tr>
		<tr>
        <td>접안예정시간 : </td>
            <td><input type="text" name="esberthtime"><br> </td>
        </tr>
		<tr>
        <td>출항예정시간 : </td>
            <td><input type="text" name="essailtime"><br> </td>
        </tr>
		<tr>
        <td>접안시간 : </td>
            <td><input type="text" name="berthtime"><br> </td>
        </tr>
		<tr>
        <td>출항시간 : </td>
            <td><input type="text" name="sailtime"><br> </td>
        </tr>
		<tr>
        <td>총물량IN : </td>
            <td><input type="text" name="totalin"><br> </td>
        </tr>
		<tr>
        <td>총물량OUT : </td>
            <td><input type="text" name="totalout"><br> </td>
        </tr>
		<td  align="center">
            <input type="submit" value="등록">
        </td>
	</form>	
</div>

<?php

}
   
?>
		
</body>
</html>