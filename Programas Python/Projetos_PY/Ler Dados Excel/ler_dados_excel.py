import pandas as pd
import numpy as np
import matplotlib.pylab as plt


plt.style.use('seaborn-whitegrid')
plt.rc('text', usetex=True)
plt.rc('font', family='times')
plt.rc('xtick', labelsize=10)
plt.rc('ytick', labelsize=10)
plt.rc('font', size=12)

'''
data = {'year': [2010, 2011, 2012, 2010, 2011, 2012, 2010, 2011, 2012],
        'team': ['FCBarcelona', 'FCBarcelona', 'FCBarcelona', 'RMadrid', 'RMadrid', 'RMadrid', 'ValenciaCF',
                 'ValenciaCF', 'ValenciaCF'],
        'wins':   [30, 28, 32, 29, 32, 26, 21, 17, 19],
        'draws':  [6, 7, 4, 5, 4, 7, 8, 10, 8],
        'losses': [2, 3, 2, 4, 2, 5, 9, 11, 11]
        }
football = pd.DataFrame(
    data, columns=['year', 'team', 'wins', 'draws', 'losses'])
print(football)
'''


edu = pd.read_csv('/Users/tiagobarbosa05/Documents/FEUP/1ºano/2º Semestre/MEST/educ_figdp_1_Data.csv',
                  na_values=':', usecols=['TIME', 'GEO', 'Value'])
print(edu)
#print(edu.head())
#print(edu.tail())
#print(edu.columns)
#print(edu.index)
#print(edu.values)
#print(edu.describe())
#print(edu['Value'])
#print(edu[10:14])
#print(edu.loc[90:94, ['TIME', 'GEO']])
#print(edu[edu['Value'] > 6.5].tail())
#print(edu[edu['Value'].isnull()].head())
#print(edu.max(axis=0))
#print('Pandas max function:', edu['Value'].max())
#print('Python max function:', max(edu['Value']))
#s = edu['Value'] / 100
#print(s.head())
#s = edu['Value'].apply(np.sqrt)
#print(s.head())
#s = s = edu['Value'].apply(lambda d: d**2)
#print(s.head())
#edu['ValueNorm'] = edu['Value'] / edu['Value'].max()
#print(edu.tail())
#edu.drop('ValueNorm', axis=1, inplace=True)
#print(edu.head())
#edu = edu.append({'TIME': 2000, 'Value': 5.00, 'GEO': 'a'}, ignore_index=True)
#print(edu.tail())
#edu.drop(max(edu.index), axis=0, inplace=True)
#print(edu.tail())
#eduDrop = edu.dropna(how='any', subset=['Value'], axis=0)
#print(eduDrop.head())
#eduFilled = edu.fillna(value={'Value': 0})
#print(eduFilled.head())
#edu.sort_values(by='Value', ascending=False, inplace=True)
#print(edu.head())
#edu.sort_index(axis=0, ascending=True, inplace=True)
#print(edu.head())
#group = edu[['GEO', 'Value']].groupby('GEO').mean()
#print(group)
#filtered_data = edu[edu['TIME'] > 2005]
#pivedu = pd.pivot_table(filtered_data, values='Value',index=['GEO'], columns=['TIME'])
#print(pivedu)
#print(pivedu.loc[['Spain', 'Portugal'], [2006, 2011]])
#pivedu = pivedu.drop(['Euro area (13 countries)','Euro area (15 countries)','Euro area (17 countries)','Euro area (18 countries)','European Union (25 countries)','European Union (27 countries)','European Union (28 countries)'], axis=0)
#pivedu = pivedu.rename(index={'Germany (until 1990 former territory of the FRG)': 'Germany'})
#pivedu = pivedu.dropna()
#print(pivedu.rank(ascending=False, method='first'))
#totalSum = pivedu.sum(axis=1)
#print(totalSum.rank(ascending=False, method='dense').sort_values())

