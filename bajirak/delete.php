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
 
    $id=$_GET[id];

 
    //데이터 삭제
    $sql = "delete from member where id = '$id'";
	
   if ($conn->query($sql) === TRUE) {
	?>  <script>
            alert("회원정보가 삭제되었습니다.");
            location.replace("./member.php");
        </script>
	<?php
   } 
   else {
      //echo "Error: " . $sql . "<br>" . $conn->error;
	  ?>  <script>
            alert("회원정보 삭제에 실패했습니다.");
            location.replace("./member.php");
        </script>
	<?php
   }
     
   $conn->close();

?>