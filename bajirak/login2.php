<?php
 
    session_start();
 
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
 
        //입력 받은 id와 password
        $id=$_GET['id'];
        $pw=$_GET['pw'];
 
        //아이디가 있는지 검사
        $sql = "select * from member where id='$id'";
        $result = $conn->query($sql);
 
 
        //아이디가 있다면 비밀번호 검사
        if($result->num_rows==1) {
			
			$row=$result->fetch_array(MYSQLI_ASSOC);
 
			//비밀번호가 맞다면 세션 생성
            if($row['pw']==$pw){
                $_SESSION['id']=$id;
                if(isset($_SESSION['id'])){
                ?>  <script>
                        alert("로그인 되었습니다.");
                        location.replace("./home.php");
                    </script>
			<?php
                }
                else{
                    echo "session fail";
                }
            }
            else {
			?>  <script>
                    alert("아이디 혹은 비밀번호가 잘못되었습니다.");
                    history.back();
                </script>
			<?php
                }
        }
 
        else{
?>          <script>
				alert("아이디 혹은 비밀번호가 잘못되었습니다.");
                history.back();
            </script>
<?php
		}
?>
