import numpy as np
import os.path
from os import path

energys = np.linspace(15,20,101)
power = np.linspace(-2.6,1.4,41,endpoint=True)
angles = 90 + 10**power
missing = 0
hit = 0
repNum = 10
temp = ""
for energy in energys:
    for angle in angles:
        for i in range (0, repNum):
            if path.exists("~/data/Simulation_run7/Emerging_tau_updated_info_reg_{}_{}_test_tmp{}.dat".format(10**energy, angle,i)) and \
            path.getsize("~/data/Simulation_run7/Emerging_tau_updated_info_reg_{}_{}_test_tmp{}.dat".format(10**energy, angle,i)) != 0:
                hit += 1
            else:
                missing += 1

print(hit, missing)
