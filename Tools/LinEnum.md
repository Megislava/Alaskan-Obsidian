- tool for privilege escalation

- how to get it onto the target system?  
1. 
- go to the directory that you have your local copy of LinEnum stored in, and start a Python web server using `python -m SimpleHTTPServer 8000"`
- using "wget" on the target machine, and your local IP, you can grab the file from your local machine [2]. Then make the file executable using the command "chmod +x FILENAME.sh"
2.     
- copy the raw LinEnum code from your local machine and paste it into a new file on the target, using Vi or Nano
- save it as .sh
- make it executable: chmod +x FILENAME.sh

- running: ./LinEnum.sh
