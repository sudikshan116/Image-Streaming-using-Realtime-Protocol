{
"cells": [
{
"cell_type": "code", "execution_count": null,
"metadata": {
"scrolled": false
},
"outputs": [],
"source": [
"import tkinter as tk\n",
16
"from tkinter import filedialog\n",
"import socket\n",
"\n",
"def send_image():\n",
" file_path = filedialog.askopenfilename(filetypes=[(\"Image files\", \"*.jpg *.jpeg
*.png\")])\n",
" \n",
" if not file_path:\n",
" return\n",
" \n",
" server_address = ('127.0.0.1', 12345)\n",
" client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)\n",
" \n",
" try:\n",
" client_socket.connect(server_address)\n",
" with open(file_path, 'rb') as image_file:\n",
" image_data = image_file.read()\n",
" client_socket.sendall(image_data)\n",
" status_label.config(text=\"Image sent successfully!\")\n",
" except Exception as e:\n",
" status_label.config(text=\"Error sending image\")\n",
" print(e)\n",
" finally:\n",
" client_socket.close()\n",
"\n",
"root = tk.Tk()\n",
"root.title(\"Image Transfer Client\")\n",
"\n",
17
"label = tk.Label(root, text=\"Image Transfer Client\")\n",
"label.pack(pady=10)\n",
"\n",
"select_button = tk.Button(root, text=\"Select Image\", command=send_image)\n",
"select_button.pack()\n",
"\n",
"status_label = tk.Label(root, text=\"\")\n",
"status_label.pack(pady=10)\n",
"\n",
"root.mainloop()\n"
]
},
{
"cell_type": "code",
"execution_count": null,
"metadata": {},
"outputs": [],
"source": []
},
{
"cell_type": "code",
"execution_count": null,
"metadata": {},
"outputs": [],
"source": []
}
18
],
"metadata": {
"kernelspec": {
"display_name": "Python 3 (ipykernel)",
"language": "python",
"name": "python3"
},
"language_info": {
"codemirror_mode": {
"name": "ipython",
"version": 3
},
"file_extension": ".py",
"mimetype": "text/x-python",
"name": "python",
"nbconvert_exporter": "python",
"pygments_lexer": "ipython3",
"version": "3.9.13"
}
},
"nbformat": 4,
"nbformat_minor": 4
}
