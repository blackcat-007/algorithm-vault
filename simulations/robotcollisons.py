import matplotlib.pyplot as plt
import imageio

positions = [3,5,2,6]
healths = [10,10,15,12]
directions = list("RLRL")

robots = list(zip(positions, healths, directions, range(len(positions))))
robots.sort()  # sort by position

frames = []

def plot_state(robots, step):
    plt.figure(figsize=(6,2))
    
    for pos, h, d, _ in robots:
        color = 'red' if d == 'R' else 'blue'
        plt.scatter(pos, 0)
        plt.text(pos, 0.1, f"{h}{d}", ha='center')
    
    plt.xlim(0, 10)
    plt.ylim(-1, 1)
    plt.title(f"Step {step}")
    plt.axis('off')
    
    filename = f"frame_{step}.png"
    plt.savefig(filename)
    plt.close()
    
    return filename

step = 0
plot_files = []

# simulate
while True:
    plot_files.append(plot_state(robots, step))
    step += 1
    
    # move robots
    new_positions = []
    for pos, h, d, i in robots:
        if d == 'R':
            pos += 1
        else:
            pos -= 1
        new_positions.append((pos, h, d, i))
    
    # sort again
    new_positions.sort()
    
    # collision handling (simple version)
    stack = []
    for robot in new_positions:
        pos, h, d, i = robot
        
        while stack and stack[-1][2] == 'R' and d == 'L':
            prev = stack[-1]
            
            if prev[1] < h:
                stack.pop()
                h -= 1
            elif prev[1] > h:
                stack[-1] = (prev[0], prev[1]-1, prev[2], prev[3])
                h = 0
                break
            else:
                stack.pop()
                h = 0
                break
        
        if h > 0:
            stack.append((pos, h, d, i))
    
    robots = stack
    
    if step > 10 or len(robots) <= 1:
        plot_files.append(plot_state(robots, step))
        break

# create GIF
images = []
for file in plot_files:
    images.append(imageio.imread(file))

imageio.mimsave("robots.gif", images, duration=1)

print("GIF saved as robots.gif")