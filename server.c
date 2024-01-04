{
"cells": [
{
"cell_type":
"code",
"execution_count":
null,
"metadata": {
"scrolled": true
},
"outputs": [
{
"name":
"stdout",
"output_type":
"stream",
"text": [
9
"Server is listening for
connections...\n",
"Connected to
('127.0.0.1',
64434)\n",
"Image received
and saved as
C:\\Users\\ajayc\\D
esktop\\Image
streaming Mini
Project\\received_i
mage_127.0.0.1.jpg
\n"
]
}
],
"source": [
"import
socket\n",
"import os\n",
"\n",
"def
save_image(image_
data,
save_path):\n",
" with
10
open(save_path,
'wb') as
image_file:\n",
"
image_file.write(i
m age_data)\n",
"\n",
"server_address =
('127.0.0.1',
12345)\n",
"save_directory =
r'C:\\Users\\ajayc\
\ Desktop\\Image
streaming Mini
Project' # Your
specified
directory\n",
"\n",
"server_socket =
socket.socket(socke
t.AF_INET,
socket.SOCK_STR
EAM)\n",
"server_socket.bind
(server_address)\n"
11
,
"server_socket.liste
n(1)\n",
"\n",
"print(\"Server
is listening for
connections...\")\n
",
"\n",
"while True:\n",
" client_socket,
client_address =
server_socket.acc
ep t()\n",
"
print(f\"Connected
to
{client_address}\")
\ n",
"\n",
" image_data =
b''
# Initialize an
empty byte string
12
to hold the image
data\n",
" while
True:\n",
" chunk = client_socket.recv(
1024)\n",
" if not
chunk:\n",
" break\n",
" image_data
+= chunk\n",
"\n",
" filename =
f\"received_image_
{client_address[0]}
.jpg\" # Use
client's IP address
in the filename\n",
" save_path =
os.path.join(save_d
irectory,
filename)\n",
"
save_image(image_
data, save_path)\n",
"\n",
13
" print(\"Image
received and saved
as\",
save_path)\n",
"\n",
"
client_socket.close(
)\n",
"\n",
"server_socket.clos
e()\n"
]
},
{
"cell_type":
"code",
"execution_count":
null,
"metadata": {},
"outputs": [],
"source": []
}
],
14
"metadata": {
"kernelspec": {
"display_name":
"Python 3
(ipykernel)",
"language":
"python",
"name":
"python3"
},
"language_info": {
"codemirror_mode"
: {
"name":
"ipython",
"version": 3
},
"file_extension":
".py",
"mimetype":
"text/x-python",
"name": "python",
15
"nbconvert_exporte
r": "python",
"pygments_lexer":
"ipython3",
"version":
"3.9.13"
}
},
"nbformat": 4,
"nbformat_minor":
4
}
