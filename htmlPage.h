#ifndef htmlPage_h
#define htmlPage_h

inline const char* htmlPage = 
R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>ESP32 Serial Terminal</title>
    <style>
		html{
		   background-size: cover;
		   height:100%;
		   background-color: #000; }
		body {
		   color: #C0C0C0;
		   font-family: Arial, san-serif; }
		h1 { margin: 10px 0 10px 0; }
		#main-form {
		   background-color:rgba(72,72,72,0.7);
		   padding: 40px 30px 40px 30px;
		   width:50%;
		   float: left;
		   left: 25%;
		   position: absolute;
		   margin-top:30px;
		   border-radius:7px;
		   -webkit-border-radius:7px;
		   -moz-border-radius:7px; } 
		#response {
			background: #fff;
		    border: 0; 
            margin-top: 10px;
			padding: 5px;
            height: 300px;
            overflow-y: auto;
            width: 100%;
		    -moz-border-radius: 4px;  
		    -webkit-border-radius: 4px;  
		    border-radius: 4px; }
        #commandForm {
			margin-top: 10px;
            width: 100%;
            margin: auto;
            display: flex;
            align-items: center; }
		#logoImg {
			text-align: right
			}
        #commandInput {
            flex-grow: 1;
            margin-right: 10px;
			background: #fff;
		   border: 0; 
		   -moz-border-radius: 4px;  
		   -webkit-border-radius: 4px;  
		   border-radius: 4px;
		   padding: 5px; }

        #checkboxInput {
            margin-right: 10px; }
		
		#sendButton {
		   cursor:pointer;
           width: 160px;
		   border:none;
		   background:#991D57;
		   background-image:linear-gradient(bottom, #8C1C50 0%, #991D57 52%);
		   background-image:-moz-linear-gradient(bottom, #8C1C50 0%, #991D57 52%);
		   background-image:-webkit-linear-gradient(bottom, #8C1C50 0%, #991D57 52%);
		   color:#FFF;
		   margin:0 0 5px;
		   margin-left: 40px;
		   margin-top: 5px;
		   padding:10px;
		   border-radius:5px; }
		#sendButton:hover {
		   background-image:linear-gradient(bottom, #9C215A 0%, #A82767 52%);
		   background-image:-moz-linear-gradient(bottom, #9C215A 0%, #A82767 52%);
		   background-image:-webkit-linear-gradient(bottom, #9C215A 0%, #A82767 52%);
		   -webkit-transition:background 0.3s ease-in-out;
		   -moz-transition:background 0.3s ease-in-out;
		   transition:background-color 0.3s ease-in-out; }
		#sendButton:active { box-shadow:inset 0 1px 3px rgba(0,0,0,0.5); }
    </style>
</head>
<body>
<div id="main-form">
	<div id="logoImg"><img src="data:image/png;base64,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"></div>
	<div><h1>ESP32 Serial Terminal</h1></div>
    <div id="commandForm">
        <input type="text" id="commandInput" name="command" placeholder="Enter command"/>
        <input type="checkbox" id="checkboxInput" name="checkbox" onclick="sendCheckbox()"/> 
        <label for="checkboxInput"><span id="checkboxInput">Echo</span></label>
		<input type="Button" id="sendButton" value="Send" onclick="sendCommand()"/>
    </div>
    <div id="response"></div>
</div>
<script>
	var evtSource = new EventSource('/events');
	evtSource.onmessage = function(event) {
		var responseDiv = document.getElementById('response');
		responseDiv.innerHTML += event.data + '<br>';
		responseDiv.scrollTop = responseDiv.scrollHeight;
	};
	function sendCommand() {
		var command = document.getElementById('commandInput').value;
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
			if (this.readyState == 4) {
				if (this.status == 200) {
					var newResponse = document.createElement('div');
					newResponse.className = 'response-item';
					newResponse.innerHTML = this.responseText;
					document.getElementById("response").appendChild(newResponse);
					document.getElementById("response").scrollTop = document.getElementById("response").scrollHeight;
				}
				else if (this.status == 400) {alert('No command provided');}
			}
		};
		document.getElementById('commandInput').value = '';
		xhttp.open("POST", "/send", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("command=" + command);
	}
	function sendCheckbox() {
		var checkbox = document.getElementById('checkboxInput');
		var checkboxValue = checkbox.checked ? '1' : '0';
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
			if (this.readyState == 4 && this.status == 200) {
				var newResponse = document.createElement('div');
				newResponse.className = 'response-item';
				newResponse.innerHTML = this.responseText;
				document.getElementById("response").appendChild(newResponse);
				document.getElementById("response").scrollTop = document.getElementById("response").scrollHeight;
			}
		};
		xhttp.open("POST", "/send", true);
		xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
		xhttp.send("checkbox=" + checkboxValue);
	}
</script>	
</body>
</html>
)rawliteral"
;


#endif