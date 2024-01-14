/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MudhoneyAudioProcessorEditor  : public juce::AudioProcessorEditor,
// Listener for combobox
private juce::ComboBox::Listener
{
public:
    MudhoneyAudioProcessorEditor (MudhoneyAudioProcessor&);
    ~MudhoneyAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // Method for combobox to be able to change things
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MudhoneyAudioProcessor& audioProcessor;
    
    // Combobox for boost switch
    juce::ComboBox boost;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MudhoneyAudioProcessorEditor)
};
