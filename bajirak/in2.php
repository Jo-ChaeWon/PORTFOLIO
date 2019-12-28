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

   //입력 받은 선적 정보
    $name=$_GET[name];
    $mno=$_GET[mno];
    $sno=$_GET[sno];
    $berth=$_GET[berth];
    $bitt=$_GET[bitt];
    $ps=$_GET[ps];
    $deadine=$_GET[deadine];
    $esberthtime=$_GET[esberthtime];
    $essailtime=$_GET[essailtime];
    $berthtime=$_GET[berthtime];
    $sailtime=$_GET[sailtime];
    $totalin=$_GET[totalin];
    $totalout=$_GET[totalout];

	//빈칸X
	if($name==NULL || $mno==NULL || $sno==NULL || $berth==NULL || $bitt==NULL || $ps==NULL || $deadine==NULL || $esberthtime==NULL || $essailtime==NULL || $berthtime==NULL || $sailtime==NULL || $totalin==NULL || $totalout==NULL) {
	?>  <script>
            alert("빈칸을 모두 채워주세요!");
            location.replace("./in.php");
        </script>
	<?php
		exit();
	}

    //입력받은 데이터를 DB에 저장
    $save = "insert into ShipList (name, mno, sno, berth, bitt, ps, deadine, esberthtime, essailtime, berthtime, sailtime, totalin, totalout) values ('$name', '$mno', '$sno', '$berth', '$bitt', '$ps', '$deadine', '$esberthtime', '$essailtime', '$berthtime', '$sailtime', '$totalin', '$totalout')";

	if ($conn->query($save) === TRUE) {
	?>  <script>
            alert("등록 되었습니다.");
            location.replace("./list2.php");
        </script>
	<?php
   } 
   else {;
	  ?>  <script>
            alert("등록에 실패하였습니다.");
            location.replace("./in.php");
        </script>
	<?php
   }
   
   $conn->close();

?>
