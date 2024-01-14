/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MudhoneyAudioProcessorEditor::MudhoneyAudioProcessorEditor (MudhoneyAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(500, 700);
    setResizable(true, true);
    
    // Make combobox visible
    addAndMakeVisible(&boost);
    // Combobox options
    boost.addItem("Normal", 1);
    boost.addItem("Boost", 2);
    
    // Default option
    boost.setSelectedId(1);
    
    // Listener for combobox
    boost.addListener(this);
}

MudhoneyAudioProcessorEditor::~MudhoneyAudioProcessorEditor()
{
}

//==============================================================================
void MudhoneyAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::orange);
    g.setFont (15.0f);
}

void MudhoneyAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    boost.setBounds(200, 80, 100, 25);
}

void MudhoneyAudioProcessorEditor::comboBoxChanged(juce::ComboBox * comboBoxThatHasChanged)
{
    audioProcessor.menuChoice = comboBoxThatHasChanged -> getSelectedId();
}
