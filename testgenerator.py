import random
import sys

PID = "PID"

def main():
	if len(sys.argv) == 2:
		PID = sys.argv[1]
	commands = ""
	template = f"./client {PID} "
	with open("test.txt", 'w') as f:
		with open("./bible.txt") as bible:
			lines = bible.readlines()
			ttllines = len(lines)
			for i in range(5):
				f.write(f"{template} \"")
				for i in range(20):
					f.write(f"{lines[random.randint(0,ttllines-1)].strip()}\n")
				f.write(f"\"\n")

if __name__ == "__main__":
	main()
