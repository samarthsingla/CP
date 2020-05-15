import pygame as pg, pygame

class Colors:
    white=(255,255,255)
    red=(255,0,0)
    green=(0,255,0)
    blue=(0,0,255)
    bg=(45,45,45)
    orange=(246,114,128)
    orange2=(232,23,93)

pygame.init()
pygame.font.init()

display_info = pygame.display.Info()
monitor_res = (display_info.current_w, display_info.current_h)

path_res = 3000 # the more the worse

w = monitor_res[0]
h = monitor_res[1]

clock = pygame.time.Clock()

disp = pygame.display.set_mode((w, h),depth=16)
running = True
n = 0
while running:
    disp.fill(Colors.bg)
    keys = pg.key.get_pressed()
    for event in pygame.event.get():
        if pygame.mouse.get_pressed()[0]:
            loc = pg.mouse.get_pos()
            print(loc[0], loc[1])
            n += 1
        if keys[pg.K_n]:
            print(n)
            exit()
