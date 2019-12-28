<!DOCTYPE html>
<html>
<head>
<style>
table, th, td {
  border: 1px solid black;
  border-collapse: collapse;
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
<title>선적 리스트</title>
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

<h2> 선적 리스트 </h2>

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

  $sql = "SELECT * FROM ShipList ORDER BY deadine ASC"; //정렬을 마감시간 기준으로 오름차순으로
  $result = $conn->query($sql);

   echo '<table class="text-center" style="width:100%"><tr>' .
          '<th>모선명</th>
            <th>모선항차</th>
	<th>선사항차</th>
	<th>선석</th>
	<th>Bitt. A/B/F</th>
	<th>접안현</th>
	<th>마감시간</th>
	<th>접안예정시간</th>
	<th>출항예정시간</th>
	<th>접안시간</th>
	<th>출항시간</th>
	<th>총물량IN</th>
	<th>총물량OUT</th>' .
	'</tr>';
		
	while($row = $result->fetch_array()){
	echo("
        <tr>
        <td align='center'>$row[name]</td>
        <td align='center'>$row[mno]</td>
        <td align='center'>$row[sno]</td>
        <td align='center'>$row[berth]</td>
        <td align='center'>$row[bitt]</td>
        <td align='center'>$row[ps]</td>
        <td align='center'>$row[deadine]</td>
        <td align='center'>$row[esberthtime]</td>
        <td align='center'>$row[essailtime]</td>
        <td align='center'>$row[berthtime]</td>
        <td align='center'>$row[sailtime]</td>
        <td align='center'>$row[totalin]</td>
        <td align='center'>$row[totalout]</td>
        </tr>
	");
	}
	echo '</table>';
 ?>

</body>
</html>