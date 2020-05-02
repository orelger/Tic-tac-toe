import random


def display_board(board):
	'''
	displat board
	'''
	print("| 7 | 8 | 9 |   | {} | {} | {} |".format(board[7],board[8],board[9]))
	print("-------------   -------------")
	print("| 4 | 5 | 6 |   | {} | {} | {} |".format(board[4],board[5],board[6]))
	print("-------------   -------------")
	print("| 1 | 2 | 3 |   | {} | {} | {} |".format(board[1],board[2],board[3]))

def player_input():
	mark=input("Player 1: What do you want choose X or O ?")
	mark=mark.upper()
	while mark not in ('X','O'):
		mark=input("Player 1: What do you want choose X or O ?")
		mark=mark.upper()

	if mark == 'X':
		return ('X','O')
	else:
		return ('O','X')

def place_marker(board,marker,position):
	board[position]=marker

def win(board,mark):

	return board[1]==board[2]==board[3]==mark or board[4]==board[5]==board[6]==mark or board[7]==board[8]==board[9]==mark or \
		board[1]==board[4]==board[7]==mark or board[2]==board[5]==board[8]==mark or board[3]==board[6]==board[9]==mark or \
		board[1]==board[5]==board[9]==mark or board[3]==board[5]==board[7]==mark
		
def who_first():
	'''
		which player will start
		if return True player 1
		else player 2
	'''
	x=random.randint(0,1)
	return x%2==0

def free_def(board):
	return ' ' in board

def next_pos(board):

	mov=int(input("Give me num between 1 to 9: "))
	while True:
		if mov in (1,2,3,4,5,6,7,8,9) and ' ' in board[mov] :
			return mov
		else:	
			mov=int(input("Give me num between 1 to 9: "))



#main
print("Tic Tac Toe Game by Orel Gershonovich")
b=[' ']*10
b[0]=1
player1,player2=player_input()
print("player 1 is: {}\nplayer 2 is: {}\n".format(player1,player2))
display_board(b)
p1=who_first()

if p1==True:
	while True:	
		print("player 1 play")
		player1Mov=next_pos(b)
		place_marker(b,player1,player1Mov)
		display_board(b)
		space=free_def(b)
		if space == True:
			pass
		else:
			break

		res=win(b,player1)
		if  res == True:
			print("player 1 win!!!")
			break
			
		print("player 2 play")
		player2Mov=next_pos(b)
		place_marker(b,player2,player2Mov)
		display_board(b)
		space=free_def(b)
		if space == True:
			pass
		else:
			break

		res=win(b,player2)
		if  res == True:
			print("player 2 win!!!")
			break


else:
	while True:
		print("player 2 play")
		player2Mov=next_pos(b)
		place_marker(b,player2,player2Mov)
		display_board(b)
		space=free_def(b)
		if space == True:
			pass
		else:
			break

		res=win(b,player2)
		if  res == True:
			print("player 2 win!!!")
			break

		print("player 1 play")
		player1Mov=next_pos(b)
		place_marker(b,player1,player1Mov)
		display_board(b)
		space=free_def(b)
		if space == True:
			pass
		else:
			break

		res=win(b,player1)
		if  res == True:
			print("player 1 win!!!")	
			break

print("End!!!")
