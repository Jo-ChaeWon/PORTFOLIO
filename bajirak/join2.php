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
    $pw=$_GET[pw];
    $pw2=$_GET[pw2];
    $email=$_GET[email];
	
	//비밀번호 중복검사
	if($pw!=$pw2) {
	?>  <script>
            alert("비밀번호를 다시 입력해 주세요!");
            location.replace("./join.php");
        </script>
	<?php
		exit();
	}
	
	//빈칸X
	if($id==NULL || $pw==NULL || $pw2==NULL || $email==NULL) {
	?>  <script>
            alert("빈칸을 모두 채워주세요!");
            location.replace("./join.php");
        </script>
	<?php
		exit();
	}
			
	
	
 
    //입력받은 데이터를 DB에 저장
    $sql = "insert into member (id, pw, pw2, email) 
	values ('$id', '$pw', '$pw2', '$email')";
	
   if ($conn->query($sql) === TRUE) {
	?>  <script>
            alert("가입 되었습니다.");
            location.replace("./login.php");
        </script>
	<?php
   } 
   else {
      //echo "Error: " . $sql . "<br>" . $conn->error;
	  ?>  <script>
            alert("아이디가 중복이니 다른 아이디를 입력해주세요.");
            location.replace("./join.php");
        </script>
	<?php
   }
     
   $conn->close();

?>